This is NOT a GEGL plugin for my users but an example of how GIMP 3.1.2's unreleased still pending GEGL Filter Browser can crash GIMP.

A GSOC student is doing great work on a tool called "GEGL Filter Browser" but it has a problem with this third party plugin example.

![image](https://github.com/user-attachments/assets/a237db4d-7986-4554-b555-be871e9aeebc)

On line 43 we see my note. Put simply the crash happens because `part2` was accidentially defined twice when it should be part one. 
I know this is invalid GEGL code but it shouldn't crash the novel Filter Browser. 

To test this compile the GEGL plugin on any version of GIMP but the official appimage and put it in 

**Windows**

 `C:\Users\(USERNAME)\AppData\Local\gegl-0.4\plug-ins`
 
**Linux**

`~/.local/share/gegl-0.4/plug-ins`
 
**Linux (Flatpak includes Chromebook)**

 `~/.var/app/org.gimp.GIMP/data/gegl-0.4/plug-ins`

Then restart GIMP and launch the novel GEGL filter browser and notice the crash.
