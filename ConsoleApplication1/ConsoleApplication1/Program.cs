using System;
using System.Diagnostics;
using System.Threading;

class Hello
{
    public static Stopwatch stopwatch = new Stopwatch();
    public static void Main()
    {
        Console.WriteLine("Hello World");
        stopwatch.Reset();
        long[] times = new long[4];
        times[0] = HelloWorld(10);
        times[1] = HelloWorld(100);
        times[2] = HelloWorld(1000);
        times[3] = HelloWorld(10000);
        
        foreach(long time in times)
        {
            Console.WriteLine(time);
        }
        Thread.Sleep(100000);

    }

    public static long HelloWorld(int repeat)
    {
        stopwatch.Start();
        for(int i = 0; i < repeat; ++i)
        {
            Console.WriteLine("Hello World");
        }
        stopwatch.Stop();
        long time = stopwatch.ElapsedMilliseconds;
        stopwatch.Reset();
        return time;
    }
}
