HSE stands for High-Speed External clock source, which is an external crystal oscillator that can be connected to the microcontroller. The HSE clock source can provide a higher frequency than the internal oscillator, which makes it ideal for applications that require high processing speed.   
The SYSCLK is used as the reference clock for the entire system and controls the speed of the CPU and other peripherals.  
 Methods to configure the SYSCLK:   
 1) First enable the required clock that used and wait untill it is ready   
 2) initialize theCPU, AHB and APB clocks according to appication requirement. Do not cross the Maximum limit.  
 3) Configure the Flash latency properly by referring to MCU RAM  
 4) Select newly enable clock as Sysclock  

STM 32 Cube IDE gives two API'S for handling the clocks. they are :  
1) HAL_RCC_OscConfig()
2) HAL_RCC_ClockConfig()
