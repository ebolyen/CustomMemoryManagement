# CustomerMemoryManagement

Custom memory management
Project Intro:
High throughput sequencing (HTS) technologies like Illumina’s GAIIx and HiSeq, allow generation of billions of bases of sequencing data in a matter of days. This explosion of data has opened a number of new research directions, but the sheer amount of data greatly strains our typical character processing algorithms and data structures.  While the amount of sequence data we can generate has been increasing exponentially over the last few years, increases in availability of addressable RAM have not kept the pace. In particular, 64-bit pointer architectures are capable of addressing much more RAM than what is typically available on today’s machines (even high performance clusters), wasting significant space in pointer-heavy data structures. One such data structure is a prefix trie. Here, the cost of keeping multiple pointers within each node of the trie makes it cost-prohibitive when trying contain read sets consisting of millions to billions of unique sequence fragments. Your goal will be to create and implement a custom memory management tool / class / layer that will be able to translate 64-bit pointers into pointers of arbitrary (used defined size). 

Inputs:
-High Throughput Sequencing (HTS) reads from real deep-sequencing experiments. You will be required to test your pipeline on multiple read sets (provided by instructor) ranging in size from 1 million 50-mers to 100 million 50 mers.

Goals:
-Design and implement a custom memory management tool / class / layer to translate 64 bit pointers into pointers of arbitrary (pre-specified) size.

Additional requirements:
-Your solution may be a full memory management layer (i.e. one that allocates chunks of heap space from the Operating System and distributes the memory chunks to your program) or some clever transformation that would reduce pointer size.
-Unless explicitly approved by the instructor, the core the pipeline must be written in C or C++.  Python wrappers to handle data input and output are OK.
-You must provide theoretical and empirical (benchmarking) ‘proof’ of how well your memory manager performs under different trie sizes.
-You must provide extensive documentation on all classes / functions that you create, as well as documentation for all external libraries you are incorporating into your project.
-You must provide benchmarks and time /space estimates on the performance of your pipeline.
