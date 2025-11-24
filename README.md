# x86-to-C_LBYARCH
x86-to-C interface programming project for LBYARCH
by Wilhelm Lee S17B

## How to Run
1. Open Terminal in the folder
2. Type "run.bat" to run the Windows Batch File

## Testing Details
### N = 2^20
ASM Average: $0.0051$ seconds
C Average: $0.0077$ seconds

The assembly (ASM) implementation is approximately $0.0026$ seconds faster on average than the C implementation for $2^{20}$ operations

### N = 2^24
ASM Average: $0.0587$ seconds
C Average: $0.0777$ seconds

The assembly (ASM) implementation is approximately $0.019$ seconds faster on average than the C implementation for $2^{24}$ operations

### N = 2^28
ASM Average: $3.5977$ seconds
C Average: $28.3269$ seconds

The assembly (ASM) implementation is approximately $24.7292$ seconds faster (nearly 8 times faster) on average than the C implementation for $2^{28}$ operations



## Sample Time/Program Speed and Correctness Verification
<img width="994" height="1002" alt="image" src="https://github.com/user-attachments/assets/67140e2d-0aef-4dca-b2ea-73d1998f00d5" />

