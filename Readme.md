To compile those sources:
-----
* create a directory build: 

      mkdir build

* go inside build: 

      cd build

* run cmake: 

      cmake ..

-> it will create all necessary file for cmake

Now to build perceptron:
* run make inside build directory: make
* and launch perceptron: ./perceptron

Configure VSCode to handle build system
-----
* install CMakeTool extension
* launch configuration: `ctrl+shift+p`
* start config: 

      cmake: Configure

=> Will launch the vscode cmake config

Now to compile and run the perceptron, just clic on play button at the bottom of VSCode windows