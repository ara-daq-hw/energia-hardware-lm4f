# energia-hardware-lm4f
This is the required Energia library dependencies for the TIVA uC (the LM4F) on the ASPS DAQ.

Go to Energia/Hardware/lm4f directory for Energia 17. Delete that directory and and replace it.

Changes to the official Energia 17 to make it work are:

Ethernet library modified. Add a begin_nonblock function which does not wait
until Ethernet completes, added a ready() function to determine when the
DHCP actually completes. 