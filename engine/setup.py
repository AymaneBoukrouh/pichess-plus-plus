from distutils.core import setup, Extension
import glob

engine_module = Extension(
  'pichess_engine',
  sources = glob.glob('wrappers/*.cpp') + glob.glob('src/*.cpp'),
  include_dirs = ['include']
)

setup(
  name = 'pichess_engine',
  version = '1.0',
  ext_modules = [engine_module]
)
