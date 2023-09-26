# MiniSTM32H723_Micropython_Port

This port is a WIP and needs [some tweaks](https://github.com/micropython/micropython/issues/12517) to the official Micropython repo in order to work.

This port uses `D8` and `D9` as `TX` and `RX` to host the REPL, you have to connect these pins to a usb-uart bridge to get to the REPL. The USB does not function right now.
