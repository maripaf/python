# dqrobotics-python [![Build Status](https://travis-ci.com/dqrobotics/python.svg?branch=master)](https://travis-ci.com/dqrobotics/python)
The DQ Robotics library in Python

**Python 2 [will retire soon](https://pythonclock.org/). We only support Python 3.**

# Installation in Ubuntu 16.04 or Ubuntu 18.04 (Users)

`python3 -m pip install dqrobotics`

Note: only binary distributions are available and they are compatible only with the Python versions available in Ubuntu 16.04 3.5 and 18.04 and 3.6. The installation will fail for any other Python version.

# Wheel compilation in Ubuntu 16.04/Ubuntu 18.04 (Developers)

Please stick to the approach above (install using pip) if you are a dqrobotics user.

## Requirements

`sudo apt-get install python3-pip python3-dev python3-setuptools python3-wheel python3-setuptools-git`

If you are allowed to upload to the dqrobotics's PyPi repo, the following is also needed

`python3 -m pip install twine`

## Build Wheel
The following commands will build a wheel compatible with your system in the folder `dist`.

### Python 3
On the root folder
`python3 setup.py bdist_wheel`

## Upload to PyPi
Before uploading to PyPi each `.whl` filename has to be changed.

Change the name `something-linux_x86_64.whl` to `something-manylinux1_x86_x64.whl`

Then upload to PyPi

`python -m twine upload dist/*`

with your PyPi credentials.