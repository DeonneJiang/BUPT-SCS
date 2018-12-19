program test(intput, output); // dgdsgdgfgsfd

type
    Date = record
            k1 :char;
            k2 :integer;
            k3 : record
                k31 : char;
                k32 : integer;
                k33 : record
                    k331: char;
                    k332 : integer
                end;
                k34 : integer;
                a2 : array[3..10]  of integer
            end;
        k4 : integer
    end;


var
    a, a1, a11 : array[0..30] of integer;
    a2 : array[3..10]  of integer;
    x, y, z : integer;  
    sd,asd,eqqq : real;
    D1 : Date;
    kkk : record
        k1 :char;
        k2 :integer;
        k3 : record
            k31 : char;
            k32 : integer;
            k33 : record
                k331: char;
                k332 : integer
            end;
            k34 : integer
        end;
        k4 : integer
    end;


procedure pro1(a : integer; b : real);
    const
        CONPRO1 = 1;
        s = CONPRO1;
    var
        t : integer;
        s : char;
    begin
        s := 1;
        writeln(1, 2, 3);
    end;

function func2(a, b:integer) : integer;
    const
        SONF = 12;
    begin
        for x := 1 to 9 do
            y := 1;
        if x = 1 then
        begin
            y := 3;
            z := 123-23;
        end;
        
        while x = 1 do
        begin
            y := 3;
            z := 123-23;
        end;
        s := 1;
        kkk.k3.k33.k333 := 1;
        D1.k3.k33.k332  := 1;
        func2 := x +y +z;
    end;


begin
    kkk.k3.k33.k332 := 1;
    kkk.k3.k33.k333 := 1;
    D1.k3.k33.k332  := 1;
    D1.k3.k33.k333  := 1;
    a2[2] := 13+12*123/123;
    pro1(1,2);
    pro1(1,2,3);
    pro(1,23);
    func2(2,2);
end.