# using the GameSparks C++ SDK with Marmalade

## HOWTO

- install python
- execute copy_sdk_sources.py (this copies SDK sources and dependencies into the GameSparks directory)
- open the sample with the Marmalade Hub

## Integration into your own projects

- execute copy_sdk_sources.py
- copy the GameSparks directory to a path of your choosing
- modify the 'subprojects' section of your mkb file to reference the GameSparks SDK:

### Example:

```
...
subprojects
{
    iwutil
    ../GameSparks/GameSparks
}
...
```
