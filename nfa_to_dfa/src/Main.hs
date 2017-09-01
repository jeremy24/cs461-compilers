


import Data.List.Split
--import System.IO
--import Control.Monad
import Data.Text (Text)
--main :: IO ()
--main = someFunc

stripSpaces :: String -> String
stripSpaces string =
    let
        repl " " = ""
        c = c
    in map repl string



--strip_spaces = do
--    (string)
--    let
--        repl " " = ""
--    map repl string



main :: IO()
main = do
    let path = "C:/source/cs461-compilers/nfa_to_dfa/solution/input1.txt"
--    handle <- openFile path ReadMode
--    contents <- hGetContents handle
    contents <- readFile path

--    lines <- splitOn "\n" contents
--    print ()
--    print (head lines)
--    initial_state <- tail (splitOn ":" (head lines))

    putStrLn  contents


--
--    initial <- lines[0]
--    final <- lines[1]
--    total <- lines[2]
--    print "Initial"
--    print initial
--    print "final"
--    print final
--    print "total"
--    print total

