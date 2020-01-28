# DAT154Oblig1

DAT154–Spring 2020–Assignment 2
Purpose: Graphics and timers. 
Part 1: Make a simple traffic lightMake a static traffic light that is drawn on the screen. Use brush and circles. The traffic light is normal with red, yellow and green.

The logic for making the traffic light must be put into the WM_PAINT part of the program. The traffic light shall change state by pressing down left mousebutton (WM_LBUTTONDOWN). Study InvalidateRect, for example on Google.Lights should change according to the normal pattern for traffic lights (Red -> Red+Yellow -> Green -> Yellow -> Red -> ... )![alt text][http://en.wikipedia.org/wiki/File:Traffic_lights_4_states.svg])

Part 2: Make two traffic lights.Make two simple roads that cross each other and place two traffic light by the crossing. To simplify, traffic is only in one direction (top->bottom, left->right). Also here the traffic lights should change when pressing down the left button (WM_LBUTTONDOWN). Note that you don’t need to draw the actual traffic yet, only lights and the road itself. 
See the image on the next page for an example of how this may look when finished

Part3: TimerStudy WM_TIMER and general about timers in the help system. Use timers to simulate the traffic lights so that the traffic lights change automatically. Select your own interval.

Part4: Cars You shall now introduce cars. Cars shall arrive from west by pressing left mousebutton down and cars from north by pressing the right button. Cars may be drawn as a square or an X.Decide for yourself if you want to make the program object oriented or not.Thecars must follow the trafficrules, that is stop on red light at the crossing, and drive when the light is green, as well as not crashing into each other (While a stack of cars can be a legit data structure, it is not a desirable outcome in the real world). Use a timer for updating the position of the cars.
Part5: Automation 
Now change the program so cars from west arrive with a probability pwper second, and cars from north arrive with probabilitypn.
pwandpnshould be set in a dialog. You now have a traffic simulator and can study how queues build up in the traffic crossing.

Part6: WM_KEYDOWNRead about WM_KEYDOWN. 
Make the program so that you change the intensitiespn and pwwith +-10% by pressing the following keys-left/right arrow (west=pw)-up/down (north = pn)You can now change pwand pnby pressing these keys described above. Just an example for how the final program can look. You don’t have to try to make it look exactly like this, your program can be more or less fancy, bigger cars, larger roads, fewer lanes, whatever you want, this is just to give you a very roughidea.
