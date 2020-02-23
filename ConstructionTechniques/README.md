## Electronic Project Construction Techniques
After an electronic project (with or without Arduino) has been prototyped and all the bugs have been worked out, the next step should be to construct it in a way that is robust, reliable, and safe. For example, you’d like to hand your project to someone and not have to say “don’t move this and don’t touch here”.


In this tutorial we will discuss some of these construction techniques.

### Contents
 - [Why Should I Care?](#why-should-i-care)
 - [Get off the Solderless Breadboard](#Get-off-the-Solderless-Breadboard)
 - Don’t Solder Modules to your Board, part 1
 - Don’t Solder WIres to your Board, part 2
 - Disadvantage to the above two methods
 - Don’t Use Solid Core Wire
 - Strip Wires as Little as Possible
 - Use Heat Shrink Tubing Instead of Electrical Tape
 - Wire Colors Matter
 - Use the Right Wire Thickness
 - Multi Conductor Cable
 - If you have multiple wires going between visible parts of your project, consider using multiple conductor cable:Wire Dressing
 - Power Connectors
 - Strain Relief
		
		
### Why Should I Care?
Very simply: To make sure your project works. I would guess that 90% of the time when I am called to fix a formerly working project, it is either because a wire has become disconnected, or a connection has occurred where it shouldn’t. Following these steps will help prevent this from happening and, if it does happen, will make it easier to find and fix the problem.



### Get off the Solderless Breadboard
The solderless breadboard is great for prototyping, but it is very unreliable. You probably experienced wires or components falling out during transportation, 
or being pulled out accidentally when moving around. Your circuit needs to be soldered. There are multiple approaches to this:
	▪	If your circuit connects to an Arduino, consider using an Arduino Prototyping Shield, such as [this one](https://store.arduino.cc/usa/proto-shield-rev3-uno-size)
	from Arduino. These are available from other vendors as well, with slight variations that you might find advantageous. What they all have in common are places for the pins that plug right into an Arduino, and a large undedicated perforated area for you to build your circuit.
	▪	If your circuit does not connect to Arduino, use a [perforated breadboard](https://en.wikipedia.org/wiki/Perfboard) (also called prototyping board or perf board) of your choice, such as [Perma-Proto boards](https://www.adafruit.com/category/466) from Adafruit which provide the connections and form factor of your solderless breadboard and might be easier for beginners. 
	There are thousands of other sizes and some different shapes (e.g. round or oval). You also have a choice as to whether there are any [pre-made connections](http://www.busboard.com/PR3UC) or [not](http://www.busboard.com/PAD1).
- [Perf boards](https://www.allelectronics.com/category/455/perf-boards/1.html) are available from most electronics suppliers
- For a more professional circuit, design and make your own printed circuit board (PCB), for example using [Fritzing and an Othermill](https://web.archive.org/web/20170723212431/http://teachmetomake.com/wordpress/using-fritzing-to-design-an-arduino-shield-and-using-othermill-to-mill-the-board). 
You can also send your design to various companies that will make your PCB for you, such as [ExpressPCB](http://www.expresspcb.com/)
		
	
	
	
###Don’t Solder Modules to your Board, part 1
Whatever technique you use to construct your circuit, you should avoid soldering any modules 
([Real Time Clocks](https://www.adafruit.com/products/264), [Bluetooth modules](https://www.adafruit.com/products/2633), etc.) to your board. Instead, solder the mating header (male or female) to your board, and plug the modules into the header:

![Socketed Sensor](images/SocketedSensor.jpg)

Note that you can get right angle headers if you prefer. Use a silver Sharpie or paint pen to indicate which way to plug in, to avoid plugging it in backwards
I can think of only two exceptions to this rule:
	1.	Space constraints
	2.	Extreme vibration (e.g. model rocket) requires something that can’t fall out
	
	
### Don’t Solder Wires to your Board, part 2 
As with modules, you should avoid soldering wires directly to your board. Instead, solder the wires to headers (male or female) and solder a mating header to your board:


Use a silver Sharpie to indicate which way to plug in, to avoid plugging it in backwards
If your wire is too thick to solder to header pins, use screw terminals instead:

I like these from Jameco:

Disadvantage to the above two methods
What happens if you plug the wires or module in the wrong way? If you’re lucky, nothing, it simply doesn’t work. But some devices will be damaged permanently by this. It is crucial to know the right way to plug things in. I always put the black wire (ground) on one side of the connector, and use a silver Sharpie to indicate where the ground should go. You can also print a label and glue it to the connectors or your board. For screw terminals, tape labels around the wires and labels on the board.
An alternative, especially for power connectors, is to use polarized barrel connectors, e.g. thisjack from Adafruit:

 
 
 
 
 
And the corresponding plug, also from Adafruit:

Don’t Use Solid Core Wire
Up to now you used solid core wire because it was easy to plug into your solderless breadboard. Solid core wire has a severe disadvantage: it is brittle and breaks easily when bent more than a few times. Even worse, soldering will create a stress point right where the wire meets the solder, making it much more likely to break. For this reason, you should always use stranded wire in projects.
The only exception I can think of is:
	1.	A wire that is soldered from one point on a board to another point on the same board:
So what do you do if you need to attach a stranded wire to a solderless breadboard? Solder a small piece of solid core wire to the stranded wire, and dress it nicely with heat shrink tubing.
Strip Wires as Little as Possible
Wires that are stripped longer than necessary leave exposed metal that might touch another wire, causing a short circuit. To avoid this, wires should be stripped no longer than whatever they are connected to.
For example, when soldering wires to the short side of header pins, strip the wire to this length. In fact, it is usually easier to strip the wire longer, tin the wire, and then trim it to the desired length.
Use Heat Shrink Tubing Instead of Electrical Tape
Electrical tape has its place, but in general, heat shrink tubing is preferred. It stays in place better and can be removed by a single cut with sharp knife. I like clear heat shrink tubing so that I can see that my connections are intact:


Colored heat shrink tubing can also be used to color-code wires, such as red for positive and black for negative
Wire Colors Matter
Use red only for +5V, use black only for GND. Use only the other colors for any other signals.
Exceptions:
	1.	Something that comes pre-wired with colors that you can’t control. In this case use heat shrink tubing to indicate the color you want it to be. If you can’t find heat shrink tubing in the color you need, use white heat shrink tubing and color it properly with a permanent marker.
Use the Right Wire Thickness
Wire thickness is specified in AWG or gauge. Thicker wires have smaller gauge numbers. Thinner wire takes up less space but tears easily, thicker wire is strong but is hard to work with. The most common wire we use is 22 AWG as it’s a good balance of these features.
If your project uses a lot of current, e.g. a heavy robot, you might need thicker wire (smaller gauge number) for the wires that carry that current, e.g. from the battery to the speed controller and then to the motor. The rest of the electronics don’t need thicker wire because they carry much less current.
Multi Conductor Cable
If you have multiple wires going between visible parts of your project, consider using multiple conductor cable:

Wire Dressing
The expression wire dressing refers to organizing and bundling wires neatly. This project for example is not well dressed:

This is an example of good cable dressing:

Note the loops of wire – this is always a good idea. It allows for necessary slack when disconnecting a wire for any reason
Power Connectors
Most power supplies come with round connectors that are called barrel- or coax- connectors:

These are a little awkward to bring into projects. You might make use of this or this connector from Adafruit.
If these connectors are such a nuisance why are they used? Because they are polarized, meaning you can’t plug them in backwards. One big disadvantage of using header pins or screw terminals is nothing prevents you from putting the wrong wire in the wrong place.
Strain Relief
Whenever wires leave a board or an enclosure think about what might happen if the wire gets yanked. The way to prevent this is to anchor the wire in some way. In this image a pair of holes have been cut near where the wire exits the box, and a zip tie is used to anchor the wire to the box:

In this project a knot is tied in the wire before it leaves the box, and the knot is glued to the box as well:

Here a ziptie is used to prevent the wire from pulling on something potentially delicate inside the box:

To prevent the wires from being pulled from this solderless breadboard, the builder has anchored the wires to the base of the breadboard:



