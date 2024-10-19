# Battery-Monitoring-System
<p>
  The BMS, or battery management system, is one of the most critical boards of the system. It handles the batteries, their protection circuitry, the deployment inhibits and arbitrates between the two power sources (batteries and solar panels). 
</p>
<h2>MCU</h2>
<p>
  The MCU on the BMS board will be an MSP430FR5989-EP, which is also the MCU used on most systems to perform commands given by the OBC. It was chosen for its incredibly low current consumption, radiation-hard-like resilience to event upsets and high reliability rating. This particular MCU will be mainly responsible for adding an extra layer of redundancy and monitoring. Proper arbitration and fail safes will be added to ensure the MCU does not trigger a protection circuit in case of a fault of its own. The MCU will also be responsible for operating the battery heaters to ensure operating temperature requirements are met. Lastly, a small version of an RLCL will be added to the MCUs power input to ensure it power cycles in case of a latchup. 
</p>
