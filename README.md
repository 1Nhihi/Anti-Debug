# Anti-Debug
<https://1nhihi.wordpress.com/2023/03/11/anti-debug-2/>
# Trong phần trên đầu tiên thì xem một vài cách trỏ tới PEB:

ví dụ trỏ tới PEB trong x32, x64

Ví dụ cách trỏ tới PEB trong WOW64

Và Kiểm tra phiên bản của hệ điều hành

cái này được nhắc đầu tiên vì trong một số code ví dụ kỹ thuật anti debug cần tới nó (GGetPEB(), GetPEB64() và IsWin8OrHigher() hay IsVistaOrHigher() ).

# Các phương pháp Anti-debugging:

IsDebuggerPresent

NtGlobalFlag

Heap Flags và ForceFlags

Trap Flag Check (TF)

CheckRemoteDebuggerPresent và NtQueryInformationProcess

NtQueryInformationProcess.

BreakPoint

# Một số cơ chế khác như:

TLS Callback

Trap Flag Check (TF)

và SEH (Structured Exception Handling)
