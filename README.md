# GPS Embedded Systems Project - Milestone 1

Till now the project can display any data on the 7-segment. It works in an asynchronous way.
Using Systick timer interrupt, We can put as much as delays as we want and still can multiplex between segments in parallel with the code. This is due to the fact the 4-digit 7 segment has only 7 pins for showing digits and 4 pins for enables which mean multiplexing is necessary to shuffle very fast between segments so they appear to be all on at the same time
This wasn't possible without interrupts because any delays in the code would delay the multiplexing

## Features

- Calculating the distance between any two points on Earth using haversine formula
- displaying the distance on the 7-segment dynamically without needing to call any functions due to using interrupts
- Delay function using Systick timer which is very accurate

## Milestone 1 Video Link - the video is in the google drive link

-[https://drive.google.com/drive/folders/1meHJXxR7G9u8Ix5Ae7IydJRoFLhzxYVj?usp=sharing](https://drive.google.com/drive/folders/1meHJXxR7G9u8Ix5Ae7IydJRoFLhzxYVj?usp=sharing)
