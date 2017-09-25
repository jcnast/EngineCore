# EngineCore
Core library to be used by all components of the engine

This is the continuation/improvement to https://github.com/jcnast/GameEngine_Deprecated

The plan here is to make a more dynamic, scalable, and longer lasting engine. If you wish to see a larger scope of the plan, please see
https://github.com/jcnast/EngineCore/tree/master/Core/__Planning, in particular, the diagram image.

To start off, I am going to create my own basic functionality. This is primarily an effort to familiarize myself more intimately with
templates and their intricacies. I am also going to be creating things on a 'as needed' basis, so that I can work on various pieces at
a time and not get bogged down in details that can be later implemented (due to the flexible design) or may never be needed
(as much as well all love writing super-detailed and infinitely robust code).

Once the core pieces that I current need are in, I am going to hook up SDL2 to open windows, manage inputs, and that sort of thing.

At this point, I should be in a state where I can implement each process in the engine in it's own time, as none should be overly
dependant on the other (if all goes as planned - not dependant at all).

While I plan on having this be very robust (and capable of running a full game) by the time I am done, to start this is very much a 
learning project. As such, I will be adding in pieces here and there to test various things that may not get fleshed out right away - but
which should not interfere with the functionality.

An example of this can be seen with the unit testing pieced together throughout. I hope to maintain some form of rigor - as I believe 
having a 100% solid foundation very important - but I am mostly bound by my desire to learn and improve my skills, so for the moment this
is, and should be viewed as, a side exercise.
