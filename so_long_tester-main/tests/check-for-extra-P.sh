#!/bin/bash

#
#
#                                                        :::      ::::::::
#   SoLongTester/check-for-extra-P.sh                   :+:      :+:    :+:
#                                                    +:+ +:+         +:+
#   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+
#                                                +#+#+#+#+#+   +#+
#   Created: 2021/03/15 14:35:10 by acesar-l          #+#    #+#
#   Updated: 2021/03/30 01:39:41 by acesar-l         ###   ########.fr
#
#

GREEN="\033[0;32m"
  RED="\033[0;31m"
RESET="\033[0m"
  MAP="maps/invalid/map-extra-P.ber"
ERROR=$(./../so_long $MAP | grep "Error" | wc -l)

if [ ${ERROR} -ge 1 ]
then
	echo -e "Check for extra P: $GREEN             [OK] $RESET"
else
	echo -e "Check for extra P: $RED             [KO] $RESET"
fi