
```bash
# это не выставлял, у меня компилятор определился самостоятельно
export CC=gcc
# установлено 
sudo apt-get install python3.10-dev
sudo apt-get install python-setuptools
sudo apt-get install python3.10-distutils
```

Компиляция c-кода в исполняемую динамическую .so библиотеку
и установка в .venv

```bash
cd src
poetry install
. ./.venv/bin/activate
python setup.py build_ext    # компиляция в папку build
python setup.py install      # установка в .venv
```
