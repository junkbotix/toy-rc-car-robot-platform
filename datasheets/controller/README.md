# On-board RC Controller

![Toy RC Car Controller](./rc-car-controller-ic-SDRX2BD.jpg)

[SDRX2BD (Super Chip) Datasheet](./SDRX2BD-BaiShengWeiElectronics.pdf)

Woohoo! This is actually a fairly standard RC controller, basically another clone of the TX2-RX2 chipset. What that means, though, is that there is plenty of information out there on how to interface to it.

Also, it means that with the pins being identified, we can easily bypass the chip, and interface directly to the on-board h-bridge circuits, assuming they all still work.

That said, in the future I will probably completely remove everything, including the steering actuator, and replace them with proper RC components (an ESC and a servo), as I have a ton of them in my junk pile as well that I've collected over the years...