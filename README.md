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


## Actual distances used in the code from Google maps

The points in the code are hard coded and these are the points from google maps with the actual distance
![distance 1 = 70 m](https://drive.google.com/uc?export=view&id=1fX6pj1rbF3kSjeLXN-UF39tad5kuO_Ze)
This distance = 70 m displayed as 71 m
![distance 2 = 150 m](https://drive.google.com/uc?export=view&id=1SXyK8B0Fn1jJiQevjKttXPJ_zPpqPyif)
This distance = 150 m displayed as 153 m

this small error is of course due to these points are selection of the points on google maps

## Team members and IDs

كيرلس اشرف صدقي داود => 1807624
انجى فايق اديب => 1806935
مارك أمجد سليم => 1701082
سوسنة ميشيل فهيم وهبه => 1809355
بيشوى اشرف فهيم => 1805453
كيرلس سمير عزيز سدرة => 1807526