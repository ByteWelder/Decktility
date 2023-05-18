uah_min=`cat /sys/class/power_supply/ltc2942/charge_full`
uah_max=`cat /sys/class/power_supply/ltc2942/charge_empty`
uah_now=`cat /sys/class/power_supply/ltc2942/charge_now`
voltage=`cat /sys/class/power_supply/ltc2942/voltage_now`
echo uAh max: $uah_max
echo uAh min: $uah_min
echo uAh now: $uah_now
echo Voltage: $voltage

