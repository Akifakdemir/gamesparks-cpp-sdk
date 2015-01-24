#!/usr/bin/python

'''
    This script copies the sources of the GameSparks SDK and the
    required dependencies.

    After execution, the GameSparks directory will contain the fully
    self contained GameSparks SDK including all the dependencies.

    you can also pass 'backward' as an argument to copy the files the
    other way around. e.g. copy the source files from the self contained
    marmalade SDK into the base directory. This is usefull, if you've made
    Changes to the SDK that you want to commit. Currently all source files
    from the self contained SDK are .gitignored
'''

import os
import sys
import shutil

BASE_DIR      = os.path.abspath(os.path.join(__file__, '..', '..', 'base'))
MARMALADE_DIR = os.path.abspath(os.path.join(__file__, '..', 'GameSparks'))

def copy_sources(SRC_DIR, DST_DIR):
    def copy(*path_parts):
        dst = os.path.join( DST_DIR, *path_parts )

        if os.path.exists( dst ):
           shutil.rmtree( dst )
        
        shutil.copytree( os.path.join( SRC_DIR, *path_parts ), os.path.join( DST_DIR, *path_parts ) )

    copy('src')
    copy('include')
    copy('dependencies', 'cjson')
    copy('dependencies', 'easywsclient')
    copy('dependencies', 'google')
    copy('dependencies', 'hmac')

def copy_forward():
    '''
        Copy sources from BASE_DIR to MARMALADE_DIR and delete unneeded platform specific headers.
    '''
    copy_sources(BASE_DIR, MARMALADE_DIR)

def copy_backward():
    '''
        Copy sources from MARMALADE_DIR to BASE_DIR.
    '''
    copy_sources(MARMALADE_DIR, BASE_DIR)

def main(direction):
    copy_function = copy_forward

    if len(sys.argv) == 2:
        direction = sys.argv[1]
        
        if direction == 'backward':
            copy_function = copy_backward

    copy_function()


if __name__ == '__main__':
    direction = sys.argv[1] if len(sys.argv) == 2 else 'forward'

    if direction not in ('forward', 'backward') or len(sys.argv) > 2:
        sys.stderr.write('Usage: %s [forward|backward]\n' % __file__)
        sys.exit(1)

    main(direction)