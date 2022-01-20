
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
. ./.venv/bin/activate
poetry env use 3.10           # при необходимости
poetry install
python setup.py build_ext     # компиляция в папку build
python setup.py install       # установка в .venv
```

Сборка wheel через cibuildwheel:
https://cibuildwheel.readthedocs.io/en/stable/setup/

```bash
cibuildwheel --platform linux  
```

Возможно, не имеет смысла запускать, для загрузки потому что pypi принимает только manylinux wheel.
```bash
python setup.py bdist_wheel 
```

```bash
python setup.py sdist         # создаем 
python -m twine upload --repository python-internals dist/*
```

