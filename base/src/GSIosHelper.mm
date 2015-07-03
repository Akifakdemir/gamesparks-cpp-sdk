#include <GameSparks/gsstl.h>
#import <UIKit/UIKit.h>

gsstl::string gs_ios_get_writeable_base_path()
{
    NSString *libraryPath = [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) lastObject];

    return [libraryPath UTF8String];
}
