const splitSnippet = (code: string, name: string): [header: string, impl: string] => {
  const lines = code.split(/(?<=\n)/); // Keep LF in each line
  const marker = new RegExp(
    `^\\s*#\\s*ifndef\\s+${name.toUpperCase()}_INCLUDED`
  );
  const start = lines.findIndex((line) => marker.test(line));
  // No header file unless there's a start marker.
  if (start === -1) return ["", code];

  let counter = 1;
  const end = lines.findIndex((line, i) => {
    if (i > start) {
      if (/^\s*#\s*endif\s*/.test(line)) return --counter === 0;
      if (/^\s*#\s*if(?:n?def)?\s+/.test(line)) ++counter;
    }
    return false;
  });
  // Put everything in header unless there's a matching `#endif`.
  // The error should make more sense that way.
  return end === -1
    ? [code, ""]
    : [lines.slice(0, end + 1).join(""), lines.slice(end + 1).join("")];
};
