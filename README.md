# AD-add-users
Program read a text file with information about users (using C++), and next add them to the Active Directory uses batch command.

In first line (!) of a file "nowiuzytkownicy.txt" we write:

organization_unit description group_name logon_script (in that order)

<br>
In next lines we write: <br>

login name surname <br>
login2 name2 surname2<br>
etc.
<br>

We run "Automat.exe" with privileges of domain administrator. 
