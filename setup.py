from Cython.Distutils import build_ext
from Cython.Build import cythonize
from distutils.core import setup
from distutils.extension import Extension

ext_modules = [
    Extension(
        name="commonstrings",
        sources=["common_multiple_strings.pyx", 
        "./common_multiple_strings/auxiliary/suffix_tree_simple.cpp",
        "./common_multiple_strings/auxiliary/alphabet.cpp",
        "./common_multiple_strings/auxiliary/utf8.cpp",
        ],
        include_dirs=["common_multiple_strings"],
        depends=['common_multiple_strings/auxiliary/alphabet.h', 'common_multiple_strings/auxiliary/utf8.h', 'common_multiple_strings/auxiliary/utf8/checked.h', 'common_multiple_strings/auxiliary/utf8/core.h', 'common_multiple_strings/auxiliary/utf8/unchecked.h', 'common_multiple_strings/auxiliary/suffix_tree_simple.h'],
        language="c++",
    ), 
]
setup(
    name = "commonstrings",
    version = "1.0.3",
    description = "Common Strings of Multiple Strings",
    long_description = "Common Strings of Multiple Strings - A fast Python library written in C++",
    author = "Pham Van",
    author_email = "kagum2996@gmail.com",
    url = "https://github.com/phamthivan2996/common_multiple_strings",
    ext_modules = ext_modules,
    setup_requires=["cython"],
    cmdclass = { "build_ext": build_ext }
)
