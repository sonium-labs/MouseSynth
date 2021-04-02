# MouseSynth
MouseSynth is a Lookup Table Synthesizer for the ATxmega128A1U.

The synthesizer is controlled via keyboard keys sent over UART, and the samples are fed in via DMA utilizing a lookup table. The waveform can be toggled between a sine wave and a triangle wave.

## Keyboard Instructions
![image](https://user-images.githubusercontent.com/36556993/113460633-6f5c9900-93e7-11eb-8308-a67dd28c325f.png)

*Note: Press 'S' on the keyboard to toggle the waveform between sine and triangle.*

## UART Specifications
Setting | Value
------------ | -------------
Baud Rate | 115200
Data Bits | 8
Parity | None
Stop Bits | 1
