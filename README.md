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
  <summary>List</summary>

- Sequence List
  ```
  cd build/bin
  ./SequenceList
  ```
- Link List
  ```
  cd build/bin
  ./LinkList
  ```

</details>



### Testing
<details>
  <summary>List</summary>

- Sequence List
  ```
  cd build/bin
  ./SequenceList_test
  ```
- Link List
  ```
  cd build/bin
  ./LinkList_test
  ```
  
</details>
