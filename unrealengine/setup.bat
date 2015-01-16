cd ..\base
python build_scripts\jenkins\main.py
cd ..\unrealengine

python setup_plugin.py
python setup_sample.py
