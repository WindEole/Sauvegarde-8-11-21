#!/bin/bash

# Define colors shorcut
Reset="^[[0m"
Bblack="^[[1;49;30m"
Bred="^[[1;49;31m"
Bgreen="^[[1;49;32m"
Byellow="^[[1;49;33m"
Bblue="^[[1;49;34m"
Bpurple="^[[1;49;35m"
Bcyan="^[[1;49;36m"
Bwhite="^[[1;49;37m"

# Define all useful variable
# 1) Architecture : architecture du systeme d'exploitation et sa version kernel
arch=$(uname -a)

# 2) CPU physical : le nombre de processeurs physiques
cpu_phy=$(cat /proc/cpuinfo | grep "physical id" | wc -l)

# 3) vCPU : le nombre de processeurs virtuels
cpu_vir=$(cat /proc/cpuinfo | grep processor | wc -l)

# 4) Memory Usage : memoire vive disponible actuelle sur le serveur et son % d'utilisation
#mem_total=$(free --mega | grep Mem: | tr -s ' ' | cut -d ' ' -f 2)
mem_total=$(free --mega | awk 'NR == 2' | awk '{print $2}')
#mem_used=$(free --mega | grep Mem: | tr -s ' ' | cut -d ' ' -f 3)
mem_used=$(free --mega | awk 'NR == 2' | awk '{print $3}')
mem_pcent=$((mem_used * 100 / mem_total))

# 5) Disk Usage : La mémoire disponible actuelle sur votre serveur ainsi que son % d'utilisation
#disk_used=$(df -h --total|grep total|cut -d ' ' -f34)
disk_used=$(df -h --total | awk 'NR == 15' | awk '{print $3}')
disk_used1=$(df --total | awk 'NR == 15' | awk '{print $3}')
#disk_total=$(df -h --total|grep total|cut -d ' ' -f38)
disk_total=$(df -h --total | awk 'NR == 15' | awk '{print $2}')
disk_total1=$(df --total | awk 'NR == 15' | awk '{print $2}')
disk_pcent=$((disk_used1 * 100 / disk_total1))

# 6) CPU load : Le taux d'utilisation actuel de vos processeurs sous forme de %
cpu_user=$(vmstat | awk 'NR == 3' | awk '{print $13}')
cpu_sys=$(vmstat | awk 'NR == 3' | awk '{print $14}')
cpu_usage=$((cpu_user + cpu_sys))

# 7) Last boot : La date et l'heure du dernier redémarrage
lastboot=$(who -b | cut -d ' ' -f12,13)

# 8) LVM use : Si LVM est actif ou pas.
lvm_count=$(lsblk | awk '{print $6}' | grep "lvm" | wc -l)
if [ $lvm_count -eq 0 ]
then
	lvm_usage="no"
else
	lvm_usage="yes"
fi
# 9) Connexions TCP : Le nombre de connexions actives.
nb_tcp_co=$(ss -t | grep ESTAB | awk '{print $1}' | wc -l)

# 10 ) User log : Le nombre d'utilisateurs utilisant le serveur.
nb_user_log=$(who | cut -d' ' -f1 | sort -u | wc -l)

# 11) Network : L'adresse IPv4 de votre serveur, ainsi que son adresse MAC (Media Access Control).
ipv4=$(hostname -I)
MAC=$(ip a | awk 'NR == 8' | awk '{print $2'})

# 12) Sudo : Le nombre de commande executées avec le programme sudo.
nb_sudo_line=$(cat /var/log/sudo/sudo.log | wc -l)
sudo=$((nb_sudo_line / 2))

# afficher a l'ecran le contenu des variables
wall -n "${Bpurple}# Architecture: ${Reset} $arch
${Bred}# CPU physical: ${Reset} $cpu_phy
${Byellow}# vCPU: ${Reset} $cpu_vir
${Bcyan}# Memory Usage: ${Reset} $mem_used/$mem_total MB ($mem_pcent%)
${Bgreen}# Disk Usage: ${Reset} $disk_used/$disk_total ($disk_pcent%)
${Bpurple}# CPU load: ${Reset} $cpu_usage%
${Bred}# Last boot: ${Reset} $lastboot
${Byellow}# LVM use: ${Reset} $lvm_usage
${Bcyan}# Connexions TCP: ${Reset} $nb_tcp_co
${Bgreen}# User log: ${Reset} $nb_user_log
${Bpurple}# Network: ${Reset} IP $ipv4 ($MAC)
${Bred}# Sudo: ${Reset} $sudo cmd"

