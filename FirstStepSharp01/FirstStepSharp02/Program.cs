using System;

namespace FirstStepSharp02
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.BackgroundColor = ConsoleColor.Black;
            Console.WriteLine("ВвЕдИ СтРоКу ДрУжоК))");
            string question = Console.ReadLine();
            System.Text.StringBuilder sb = new System.Text.StringBuilder(question);
            for (int j = 0; j < sb.Length; j++)
            {
                if (j % 2 == 0)
                {
                    sb[j] = System.Char.ToUpper(sb[j]);
                }
            }
            string corrected = sb.ToString();
            System.Console.WriteLine(corrected);
        }
    }
}
