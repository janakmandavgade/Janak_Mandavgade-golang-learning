package main

import (
	"io"
	"os"
	"strings"
)

type rot13Reader struct {
	r io.Reader
}

func (rot rot13Reader) Read(b []byte) (int ,error){
	
	n, err := rot.r.Read(b)
	if err != nil {
		return n, err
	}
	
	for i:= 0 ; i < n; i++ {
		b[i] = rot13(b[i])
	}
	
	return n, nil;
}

func rot13(b byte) byte {
	var base byte
	switch {
	case b >= 'A' && b <= 'Z':
		base = 'A'
	case b >= 'a' && b <= 'z':
		base = 'a'
	default:
		return b
	}
	return (b-base+13)%26 + base
}

func main() {
	s := strings.NewReader("Lbh penpxrq gur pbqr!")
	r := rot13Reader{s}
	io.Copy(os.Stdout, &r)
}
