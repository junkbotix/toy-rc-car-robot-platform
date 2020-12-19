# Interfacing

There are two methods we can use to interface with the on-board controller. We can first just bypass the chip entirely, and interface directly with the on-board h-bridges:

[RX2 Bypassing](./rx2-bypassing)

Or, we can simulate and directly "inject" a signal into pin 3 of the RX2 chip:

[Direct Signal Injection](./signal-injection)

## Thunder XX - Controller Notes

This is just a section I have included with some of my notes and such attempting to reverse engineer the schematic for the controller on the vehicle. I found that it didn't match any reference diagram included in the datahseets I had found. But it was similar enough for me to find my way around, and understand what controlled what on the board.