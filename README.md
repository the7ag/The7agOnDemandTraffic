#System Description:
A simple traffic lights system using Atmega32 and 6 led 3 for the cars
traffic light and 3 for the pedestrians traffic lights and one push button
for the pedestrians
#System Design
This system runs on two mode the normal mode and the pedestrian
mode and it switches between them with the push button
1-Normal Mode
In this mode the cars traffic light starts on green then the yellow light
starts blinking after 5 seconds and then the red lights turn on for 5
seconds and then the yellow light starts blinking for 5 seconds and it
turns green again
And the pedestrians led is on red light
2-Pedestrian mode
This mode happens when the button is pushed it have some conditions
that it must follows
If the button is pressed while the cars traffic light is on Red then the
pedestrians led should turn to green and stay on green for 5 seconds
and then both the yellow lights should blink for 5 seconds and then the
pedestrian's red light should turn on and the cars green light should
turn on and after 5 seconds, we return to the normal mode again
If the button is pressed while the cars traffic light is on yellow or green
both yellow lights should blink for 5 seconds and then the cars red light
should turn on and the pedestrians green light should be turned on for
5 seconds after that we return to the normal mode again
#System Flow Chart:
![OnDemandTrafficLight](https://user-images.githubusercontent.com/95578914/188331557-0a09d1f1-4263-4bd6-8eb0-19e1ccdfaea9.png)
#System Constraints:
This system follows the same pattern every cycle of it and nothing
changes it's state other than the push button and should only be
changed when the button is pressed once so a double click or a long
press shouldn't affect the system cycle and once a cycle has begun it
cannot be stopped until the system is resets
