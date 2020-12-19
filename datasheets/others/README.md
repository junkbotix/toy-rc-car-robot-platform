# Other clones of the TX2-RX2 chipset

Many companies over the years have cloned the Realtek TX2-RX2 "5 functions" chipset. They are almost all pin-compatible, but some have very subtle differences to be aware of in this regard.

The original chipset, for instance, had a couple of pins to inhibit the right and left turning outputs. I have yet to see these used in any design, and none of the datasheets which show a "reference implementation" schematic show them being used. Some manufacturers repurposed those pins to provide other functionality. Be sure to read the datasheet for your manufacturer's version carefully!