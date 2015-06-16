"""
	Here are the most important per project settings.
	This file is here, because we need to do additional substitutions in the
	header.html and footer.html

	If you need further control over the Doxygen process, please feel free to modify
	Doxyfile.in

	This process might not be perfect but is designed to give you a nice starting point quickly

	Also do not forget to replace files/logo.png with something suitable.
"""

project_name = 'GameSparks C++ SDK'
project_tagline = 'The #1 Backend-as-a-Service platform for game developers'

# The INPUT tag is used to specify the files and/or directories that contain
# documented source files. You may enter file names like myfile.cpp or
# directories like /usr/src/myproject. Separate the files or directories with
# spaces.
# Note: If this tag is empty the current directory is searched.
doxygen_input = (
	# here we're using pythons brace-continuation to organize the long list of inputs. Don't forget to put a space at the end of the string-fragment.

	# source files
	'../base/include '
	'../base/src '

	#Guides
	'../base/guide/README.md '
	'../marmalade/guide/README.md '
	'../cocos2dx/guide/README.md '

	# Readmes
	'../README.md '
	'../base/README.md '
	'../marmalade/README.md '
	'../cocos2dx/README.md '
	'../unrealengine/README.md '
	#'../testing/README.md'
)


# The EXCLUDE tag can be used to specify files and/or directories that should be
# excluded from the INPUT source files. This way you can easily exclude a
# subdirectory from a directory tree whose root is specified with the INPUT tag.
#
# Note that relative paths are relative to the directory from which doxygen is
# run.
doxygen_exclude = (
	''
)

doxygen_example_path = '../base/samples'

template = 'bitbucket' # must be one of 'github', 'bitbucket', 'plain'

# these only need to be set, if use_github_pages is true
forkme_url = 'https://bitbucket.org/gamesparks/gamesparks-cpp-sdk/'
zip_download_url = 'https://bitbucket.org/gamesparks/gamesparks-cpp-sdk/get/HEAD.zip'
tar_download_url = 'https://bitbucket.org/gamesparks/gamesparks-cpp-sdk/get/HEAD.tar.gz'
maintainer_name = 'GameSparks'
maintainer_url = 'http://www.gamesparks.com/'
logo_href = 'http://www.gamesparks.com/'

HAVE_DOT = 'YES' #set to YES if you have graphviz, to NO otherwise. Setting it to YES increases the time it takes to generate the documentation
