BEGIN {
    OFS = "";
    ORS = "";
}
/^[ABC]/ {
    print $1,$2;
}
