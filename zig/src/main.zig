const std = @import("std");

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();
    const stdin = std.io.getStdIn().reader();

    var input: [8]u8 = undefined;
    try stdout.print("Input: ", .{});
    if (try stdin.readUntilDelimiterOrEof(input[0..], '\n')) |value| {
        try stdout.print("{s}\n", .{value});
    } else {
        try stdout.print("No Input\n", .{});
    }
}
