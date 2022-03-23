# levle 1 

<strong> Given problem: </strong>

<img width="1311" alt="Screenshot 2021-12-29 at 21 19 21" src="https://user-images.githubusercontent.com/47741591/147759260-3ec8b925-d495-4b55-be8c-b44f3fb42f37.png">

<strong> The same configuration in GNS3 </strong>

<img width="1210" alt="Screenshot 2021-12-29 at 19 19 39" src="https://user-images.githubusercontent.com/47741591/147687586-e5242e07-e002-4227-bedf-8fa69573b0f9.png">

Here I give the ip address to both my PC and my little brothers computer such that they fall in to the same subnet.

<img width="824" alt="Screenshot 2021-12-30 at 16 28 27" src="https://user-images.githubusercontent.com/47741591/147760620-bf495cb2-4452-41f7-adcb-8f855e6a8e4a.png">

We ping each address and see that the packets are able to go where they need to!

<img width="441" alt="Screenshot 2021-12-30 at 16 42 03" src="https://user-images.githubusercontent.com/47741591/147761633-3f2635f6-949c-40b1-addd-2861595994e7.png">


<img width="433" alt="Screenshot 2021-12-30 at 16 42 08" src="https://user-images.githubusercontent.com/47741591/147761626-5d3ce0b0-adea-41f7-8ba7-d7c5247b4e6f.png">


### *Hmm..* but WHY do they have to be on the same network in order for them to communicate?

Take a look at what *Wireshark* found inspecting the network trafick between the 2 hosts.

104.95.23.12 pings 104.95.23.13

<img width="1203" alt="Screenshot 2021-12-30 at 16 40 45" src="https://user-images.githubusercontent.com/47741591/147761519-7731723e-e43c-4e66-8c4c-17d2fad02605.png">

104.95.23.13 pings 104.95.23.12

<img width="1196" alt="Screenshot 2021-12-30 at 16 39 02" src="https://user-images.githubusercontent.com/47741591/147761506-abd8b673-7f52-40cd-87f3-79b71c201991.png">

The answear is the *yellow* colored row. When a machine would like to send some data to an **ip address** it has to find out what **mac address** it has, so it uses the **arp protocol** to discover what **mac address** a sertain **ip address** has. So the message is sent to every machine connected in the network and if the machines **ip address** matches it responds with it's **mac address** and if the ip address does not match I think it is ignored. If the **ip address** is not on the same **network** it will not get discovered and communication will not happen.

### Why is there no arp request when .13 pings .12?

<img width="1084" alt="Screenshot 2021-12-30 at 16 36 34" src="https://user-images.githubusercontent.com/47741591/147761941-21e44873-4be9-4bc3-bb8c-8025928c18f2.png">

Because the mac address of each machine are saved in the **arp table** and both machines know what **ip address** coresponds to what **mac address**.

### What other **ip address** would work and which **ip address** would not?

What I noticed is that both ip address have to be in side the range of ***smallest subnet***. For example 104.95.23.12/16 pings 104.95.23.13/24 since 104.95.23.12/16 is in side of  104.95.23.13/24. There are probabliy some other way to make it work but for now I stoped here.


#### Passing result:

<img width="1276" alt="Screenshot 2021-12-30 at 17 09 54" src="https://user-images.githubusercontent.com/47741591/147763831-1831c03a-473f-4ad4-a70c-b8deea6e4868.png">
