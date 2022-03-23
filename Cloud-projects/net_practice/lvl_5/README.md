### Assigment
<img width="1287" alt="Screenshot 2021-12-31 at 08 16 52" src="https://user-images.githubusercontent.com/47741591/147806920-62cab5c5-80b9-45ad-9c34-137467c51403.png">

## Okay before we start lets explain what are these 2 fields:

<img width="273" alt="Screenshot 2022-01-02 at 12 38 19" src="https://user-images.githubusercontent.com/47741591/147873206-13fa338d-af62-4a4b-89b8-9d96676b3634.png">

Both togetter they make up a rauting table. So the first field is what and the 2nd is to where. So if the 1st filed has 0.0.0.0/0 or default and if the address we want to communicate with is in the same range subnet theb send it to the 2nd filed which is the default gateway and should match the IP address of a interface that u want to send the trafic to.

### GNS3:

<img width="686" alt="Screenshot 2021-12-31 at 15 39 49" src="https://user-images.githubusercontent.com/47741591/147826168-3ab293b1-cc80-46a0-8012-7a8ff8b34c24.png">

The only interesting thig here is the **arp request**. Since Client A sees that Client B is on a diffrent network it will use the **default gatweay** to communicate, so the **arp request** is for the router. And then the router sends an **arp request** to Client B to learn its **mac address**. The only thing I do not understand is why does the router send an **arp request** to client A at the end, because **mac address's** would have been exchanged once Client A learned about the routers **mac address**.

### From interface R2
<img width="1267" alt="Screenshot 2021-12-31 at 15 37 57" src="https://user-images.githubusercontent.com/47741591/147826152-56757468-b9d7-4748-b68d-f446b5eb10b8.png">

### From interface R1
<img width="1255" alt="Screenshot 2021-12-31 at 15 38 15" src="https://user-images.githubusercontent.com/47741591/147826158-4c0c142c-69f6-4dfb-9d5e-9db49a17f29d.png">

### the solution
<img width="1299" alt="Screenshot 2021-12-31 at 08 19 17" src="https://user-images.githubusercontent.com/47741591/147806986-ec59e173-1ec4-4dfa-846b-452353fed719.png">
