# max202Communication
In this repository there are some helps about the communication with Arduino and for example ConfAir machine through MAX202 component, so checksum calculation and the printing of the message.

First of all, me and my schoolmate have created some functions about this communication:
1) Checksum calculation, in fact to send the message to a machine like Zehnder ConfAir Standard 350, you must need to calculate the checksum, so the function 'calculateChecksum' calculate for you the checksum, you only need to inizialize the checksum in the message at 0. In this function, you must pass as parameters the byte vector message and the number of byte which the message must have.

2) Message print ('stampaMEssaggio'), in fact to read the message which you send, you have to understand easier the message and this function do as you please. The message is structured into its various parts, you must only pass as parameters the byte vector message and the number of bytes of the message.

3)'stampaRisposta' which allows you to read the response that the machine send you in return after sending message. You must only pass as parameters the byte vector response, inizialized at 0, and the number of byte that the response must have.

4) There are also an extra function that you can use to test the functioning of the library. You only need to call the function 'prova' without parameters.
