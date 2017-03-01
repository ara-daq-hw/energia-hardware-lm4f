# energia-hardware-lm4f
hardware/lm4f directory for Energia 17. Delete that directory and and replace it.

Changes to the official Energia 17:

Ethernet library modified. Add a begin_nonblock function which does not wait
until Ethernet completes, added a ready() function to determine when the
DHCP actually completes. 