## On Linux
```bash
sudo update
sudo apt install gcc-arm-none-eabi
# TO Verify
arm-none-eabi-gcc --version
```


## Arch linux
```bash
sudo pacman -S arm-none-eabi-gcc
```

## On Mac
```bash
brew install arm-none-eabi-gcc
```
## On Windows
Using Chocolatey:
```</>Power shell
choco install gcc-arm-embedded
```



SRC: https://github.com/inpyjama/stm32-renode/tree/main
Intro to renode : https://interrupt.memfault.com/blog/intro-to-renode



#### Commands 

cmake -B ./build ./


arm-none-eabi-objdump -D lab1
xxd lab1 |less
arm-none-eabi-size lab1