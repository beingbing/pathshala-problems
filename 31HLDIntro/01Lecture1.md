# Understanding Web Architecture - Frontend

Created a website using HTML, CSS, and JS. Now want to make it available on myblogs.com. How
to do it?

## Hosting a Website

### 1. Basic Idea
If you store your website's HTML, CSS, and JavaScript files on a personal machine, it won't be
accessible 24/7. To make it available to everyone at any time, you need to place these files on a
machine, which is always running and accessible via the internet. This process is called deploying
or hosting.

### 2. Accessing Your Code Online
Every machine on the internet has an address called an IP address. Suppose your machine's IP
address is `24.144.132.207`. To access your `index.html` file, someone would type:
```sh
24.144.132.207/index.html
```
This instructs the browser to go to the machine with the specified IP address and retrieve the
`index.html` file.

### 3. Using Domain Names
Remembering IP addresses can be difficult. To solve this, we use domain names. You can purchase a
domain name and pay for it to keep it active. A domain name maps to an IP address, a process
managed by Domain Name Servers (DNS). When you type a domain name in the browser, the browser first
queries the DNS to get the corresponding IP address, then requests the relevant files from that
machine.

### Client-Server Architecture
The machine hosting your HTML, CSS, and JS files is called the frontend server, and your browser
acts as the client. This setup forms a simple two-tier architecture for static websites, where the
frontend server hosts files known at development time.

| | | |
| - | - | - |
| | Request | |
| | ---------> | |
| Client| | Front-end Server |
| | <--------- | |
| | Response | |

> Note: A browser is software that understands how to process and render HTML, CSS, and JS files.
> Different browsers may interpret these files slightly differently, leading to variations in how
> websites are displayed.