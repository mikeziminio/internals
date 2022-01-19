from setuptools import setup, Extension

setup(
    name="internals",
    version="0.1.0",
    ext_modules=[
        Extension('internals', ['c/internals.c'], include_dirs=["/usr/include/python3.10"])
    ]
)
