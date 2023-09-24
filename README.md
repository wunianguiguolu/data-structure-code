# data-structure-code

### Set up envinronment

```
git clone git@github.com:catchorg/Catch2.git
cd Catch2
cmake -Bbuild . -DBUILD_TESTING=OFF
cmake --build build/ --config release --target install
```

```
cd data-structure-code
mkdir build
cd build
cmake ..
make
```

### Running
<details>
  <summary>Square Lattice</summary>


- exact count
  ```
  cd scripts/Square
  sh ./run_Square_exact.sh
  ```

- Monte Carlo 
  ```
  cd scripts/Square
  sh ./run_Square_MC.sh
  ```
  
- Monte Carlo Prototype 
  ```
  cd scripts/Square
  sh ./run_Square_MC_Prototype.sh
  ```

</details>
<details>
  <summary>SequenceList</summary>
  ```
  cd build/bin
  ./SequenceList
  ```

</details>



### Testing
<details>
  <summary>SequenceList</summary>
  ```
  cd build/bin
  ./SequenceList_test
  ```
</details>
