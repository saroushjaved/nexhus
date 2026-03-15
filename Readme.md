# NEXHS - Native EXecution for Heterogeneous Systems


**NEXHS (Native Execution for Heterogeneous Systems)** is a framework designed to provide high-performance computational libraries that can execute efficiently across heterogeneous computing platforms. Modern computing systems increasingly combine multiple types of processing elements such as CPUs, GPUs, FPGAs, and domain-specific accelerators. While these devices offer significant performance advantages for particular workloads, programming them typically requires device-specific implementations and manual workload partitioning, which increases development complexity and limits portability.

NEXHS addresses these challenges by offering a collection of optimized computational primitives together with a runtime environment capable of transparently mapping these operations to the most appropriate hardware resource. NEXHS exposes high-level software APIs for common compute-intensive operations—such as signal processing, linear algebra, and data processing—while internally providing multiple hardware-specific implementations. When an application invokes a NEXHS function, the runtime system determines the best available execution target based on available devices, workload characteristics, and performance considerations.

The framework therefore allows developers to write applications using a unified programming interface while leveraging the performance benefits of heterogeneous hardware platforms. By abstracting device management, scheduling, and data movement, NEXHS simplifies the development of high-performance applications and improves performance portability across different computing architectures.

Overall, NEXHS aims to bridge the gap between high-level software development and heterogeneous hardware acceleration by providing a flexible, scalable, and hardware-agnostic acceleration library that can seamlessly utilize CPUs, GPUs, FPGAs, and other specialized compute resources.


## Available RTL IP Blocks 
### Nexhus Fast Fourier Transform

**Repository:** https://github.com/saroushjaved/nexhus-fft

A parameterizable **hardware FFT accelerator written in SystemVerilog** designed for FPGA implementation. The project implements a scalable radix-2 FFT pipeline supporting sizes up to 1024 points and integrates **AXI4 and AXI4-Lite interfaces** for memory access and control, enabling easy integration into SoC designs. It includes RTL modules for stage computation, twiddle ROM generation, memory interfacing, and a self-checking simulation testbench for functional verification.
