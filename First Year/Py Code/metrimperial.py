feetAndInches = input("Enter feet & inches: ")

feet, inches = feetAndInches.split("'")

feet = int(feet)
inches = int(inches)

length = 12*feet + inches
metres = 0.0254 * length

print(feetAndInches,"is ", metres, " metres")