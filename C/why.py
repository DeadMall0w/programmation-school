startValue = 5380.08



endValue = 1949.78




credit = [311.25,0.88,39.55,.98,14.76,33.14,68.13,40.97,43.60]
# totalCred = 0
debit = [7.99,18.95,349.53,3455.50,152.59]
# totalDeb = 0

for c in credit:
    startValue += c

for d in debit:
    startValue -= d


print(f"Start value = {startValue} & end value = {endValue}")