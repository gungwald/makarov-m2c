MODULE MayanNums;
(* Mayan numerals *)

FROM InOut IMPORT ReadString, WriteLn, WriteString, WriteInt, WriteCard;
FROM String IMPORT Copy, Length;
FROM ShellVars IMPORT GetNArg, GetNthArgStr;

CONST
  MaxM = 20; (* maximum number of digits *)

TYPE
  TMayanDigit = ARRAY [0 .. 4] OF CHAR; (* a single digit *)
  TLS = ARRAY [0 .. 5] OF TMayanDigit;

VAR
  D : ARRAY [1 .. MaxM] OF CARDINAL;
  InputNumber: ARRAY [1 .. MaxM] OF CHAR;
  I, J, L, M, S: CARDINAL;
  N: INTEGER;
  LS: TLS;

PROCEDURE GetNumberFromUser(VAR InputNumber:ARRAY OF CHAR);
VAR
  ArgCount: CARDINAL;
BEGIN
  ArgCount := GetNArg();
  WriteCard(ArgCount, 2);
  WriteLn;
  IF ArgCount > 1 THEN
    GetNthArgStr(1, InputNumber);
    WriteString(InputNumber);
    WriteLn;
  ELSE
    WriteString("Number: ");
    ReadString(InputNumber);
  END;
END GetNumberFromUser;

BEGIN
  LS[0] := "    ";
  LS[1] := " .  ";
  LS[2] := " .. ";
  LS[3] := "... ";
  LS[4] := "....";
  LS[5] := "----";

  GetNumberFromUser(InputNumber);
  M := Length(InputNumber);

  IF M > MaxM THEN M := MaxM END;
  FOR I := 1 TO M DO
    D[I] := ORD(InputNumber[I]) - ORD("0");
  END;
  FOR J := M - 1 TO 1 BY -1 DO
    FOR I := 1 TO J DO
      D[I + 1] := D[I + 1] + 10 * (D[I] MOD 2);
      D[I] := D[I] DIV 2               
    END
  END;
  S := 1;
  WHILE (D[S] = 0) AND (S < M) DO
    S := S + 1
  END;
  FOR I := S TO M DO
    WriteString("+----")
  END;
  WriteString("+");
  WriteLn;
  FOR L := 0 TO 3 DO
    FOR I := S TO M DO
      IF (D[I] = 0) AND (L = 3) THEN
        WriteString("| @  ")
      ELSE
        N := D[I] - 5 * (3-L);
        IF N > 5 THEN
          N := 5
        ELSIF N < 0 THEN
          N := 0
        END;              
        WriteString("|");
        WriteString(LS[N]);
      END
    END;
    WriteString("|");
    WriteLn
  END;
  FOR I := S TO M DO
    WriteString("+----")
  END;
  WriteString("+");
  WriteLn
END MayanNums.
