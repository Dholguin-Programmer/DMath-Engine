import shlex
import subprocess
import getopt
import os
import sys

# Repo Name
REPO_NAME = "DMath-Engine"

# Extract Environment Variables 
INSTALL_PREFIX = str(os.getenv('OE_INSTALL_PREFIX'))
OE_ENVIRONMENT_SETUP = bool(os.getenv('OE_ENVIRONMENT_SETUP'))
TARGET_OS = str(os.getenv('TARGET_OS'))

# Directory Relavent Variables
DMATH_ENGINE_SOURCE_DIR = os.path.dirname(os.path.realpath(__file__))
DMATH_ENGINE_BUILD_DIR = INSTALL_PREFIX + "/" + str(REPO_NAME)

# TODO: Add windows support

def create_directory_if_not_exist(dirName):
     if not os.path.exists(dirName):
          os.makedirs(dirName)  

def build_linux(toolchain):
     create_directory_if_not_exist(DMATH_ENGINE_BUILD_DIR)
     
     # Right now we only have one target but use subprocess to future
     # proof our build process in a possible future cases where although
     # the target is the same, we might have different 'CARDS' of which
     # our executable will be ran on

     # Setup arguments we'll be passing into CMake
     cmake_arguments  = " -GNinja" # Use the Ninja Generator
     cmake_arguments += " -S" + str(DMATH_ENGINE_SOURCE_DIR) # Specify Source Tree
     cmake_arguments += " -B" + str(DMATH_ENGINE_BUILD_DIR)  # Specify Buiild Tree

     subprocess.run(["cmake" + cmake_arguments], shell=True, cwd=DMATH_ENGINE_BUILD_DIR)
     subprocess.run(["ninja"], shell=True, cwd=DMATH_ENGINE_BUILD_DIR)


def build_dme(build_arguments):
     toolchain = ""

     try:
          opts, args = getopt.getopt(build_arguments,"h")
     except getopt.GetoptError:
               print(__file__ + ': Failed to parse arguments')
               sys.exit(2)

     for opt, arg in opts:
          if opt == '-h':
               print("TODO: define valid arguments")
               sys.exit()

     if OE_ENVIRONMENT_SETUP == True:
          if TARGET_OS == 'linux-gnu':
               build_linux(toolchain)
          else:
               print(__file__ + "Unsupported OS: " + TARGET_OS)
     else:
          print(__file__ + ': Please source a xdev file')

if __name__ == "__main__":
     build_dme(sys.argv[1:])
