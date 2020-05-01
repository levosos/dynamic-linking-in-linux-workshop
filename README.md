# Dynamic Linking in Linux

### What Is This?

A fully reproducible workshop along with a [presentation](https://docs.google.com/presentation/d/1OjgcYJoBmHl0yh0PTpbpv5GndQ3uGH4kTk1ez8OWep0/edit?usp=sharing).

### Topics

Deep diving into ELF files and dynamic linking in Linux:
* Overviewing famous ELF sections and segments
* Examining compiled ELF files
* Using LD_PRELOAD to hook dynamic symbols
* Using relocation information to hook dynamic symbols

### How Can I Run It Myself?

The workshop requires a Linux system with `gcc`, `readelf`, `objdump`, and `less`.
You can use the provided docker image to run the workshop.

#### Build the Image

`docker build -f Dockerfile . -t dynamic-linking-in-linux-workshop`

#### Run the Container

`docker run -it --rm -v ${PWD}:/workshop -w /workshop dynamic-linking-in-linux-workshop`

#### Run the Workshop

Follow the presentation slides and use the commands documented within the source files to build and run at each step.
Run all commands from the root directory of the workshop.
