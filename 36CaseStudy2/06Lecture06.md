# Virtual Machines

Now, before going back to our system design problem, lets understand another concept which will
help us in creating a resilient architecture. Virtual Machines -

Deployment means moving our code to a machine connected to internet so that it can be accessed
by other users. But what if while writing the code we were on different OS and the machine on
which we want to deploy has different OS. We need to understand here that code is in fact a
platform dependent entity. That's why OS plays a crucial role in structuring a code. 

example,
while naming files and folders Windows OS is case-insensitive whereas Linux is case-sensitive,
hence while accessing a file in code we need to be careful of case sensitivity in case of Linux.

Another example is the executable files created, as macOS has .dmg extension whereas Windows OS
has .exe extension.

###
---
###

Because of all these issues, to be able to run multiple OS on a single machine, there are two
different ways -
#### multiple boot
we create partition of our hardware, and we install different OS for different parts. And then we
can decide to boot any one of them at a given time. This approach is faster but it is very limiting.

#### virtual box
we do virtualization. At bottom, we have Pieces of hardware, on which a Host OS is installed. On
it a software is installed called Hypervisor. What it does is, it lets you create different
processes which in itself acts as a Hardware (virtual) thus allowing you to install OS along with
its operational (system call) libraries and use it as a completely new machine. Hypervisor make the
process OS feel like it is installed on an actual machine with complete access to it. so, it acts
as a broker between Host OS and process OS. And this phenomenon of hypervisor making a process OS
perform all duties of a native OS is termed as a virtual machine. And using VMs we can run platform
dependent code.

###
---
###

But this platform dependent code is a hassle. We are just complicating handling of code, which is
completely unnecessary. To solve this, we came up with containerisation.

Let's dive into containerisation next.
